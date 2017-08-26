#ifndef INCLUDE_MODELS_HPP_
#define INCLUDE_MODELS_HPP_

#include <array>
#include <string>
#include <utility>
#include <vector>

#include <boost/random/normal_distribution.hpp>
#include <boost/random/uniform_smallint.hpp>
#include <boost/random/discrete_distribution.hpp>
#include <boost/math/distributions/normal.hpp>


#include "cpprob/cpprob.hpp"
#include "cpprob/distributions/multivariate_normal.hpp"

namespace models {
template<class RealType = double>
void gaussian_unknown_mean(const RealType y1, const RealType y2)
{
    using boost::random::normal_distribution;
    normal_distribution<RealType> prior {1, std::sqrt(5)};
    const RealType mu = cpprob::sample(prior, true);
    const RealType var = std::sqrt(2);

    normal_distribution<RealType> obs_distr {mu, var};
    cpprob::observe(obs_distr, y1);
    cpprob::observe(obs_distr, y2);
    cpprob::predict(mu, "Mu");
}


template<class RealType=double>
void gaussian_2d_unk_mean(const std::vector<RealType> y1)
{
    using boost::random::normal_distribution;
    cpprob::multivariate_normal_distribution<> prior{{1,2}, {std::sqrt(5),std::sqrt(3)}};
    const auto mu = cpprob::sample(prior, true);
    const RealType var = std::sqrt(2);

    cpprob::multivariate_normal_distribution<RealType> likelihood {mu.begin(), mu.end(), var};
    cpprob::observe(likelihood, y1);
    cpprob::predict(mu, "Mu");
}

template<class RealType = double>
struct Gauss {
    void operator()(const RealType y1, const RealType y2) const
    {
        using boost::random::normal_distribution;
        normal_distribution<RealType> prior {1, std::sqrt(5)};
        const RealType mu = cpprob::sample(prior, true);
        const RealType var = std::sqrt(2);

        normal_distribution<RealType> obs_distr {mu, var};
        cpprob::observe(obs_distr, y1);
        cpprob::observe(obs_distr, y2);
        cpprob::predict(mu, "Mu");
    }
};

template<std::size_t N>
void linear_gaussian_1d (const std::array<double, N> & observations)
{
    using boost::random::normal_distribution;

    double state = 0;
    for (const auto obs : observations) {
        normal_distribution<> transition_distr {state, 1};
        state = cpprob::sample(transition_distr, true);
        normal_distribution<> likelihood {state, 1};
        cpprob::observe(likelihood, obs);
        cpprob::predict(state, "State");
    }
}

template<class RealType=double>
void normal_rejection_sampling(const RealType y1, const RealType y2)
{
    using boost::random::normal_distribution;
    using boost::random::uniform_real_distribution;
    using boost::math::pdf;

    const RealType mu_prior = 1;
    const RealType sigma_prior = std::sqrt(5);
    const RealType sigma = std::sqrt(2);

    const int max_it = 10000;

    // Sample from Normal Distr
    const auto maxval = pdf(boost::math::normal_distribution<RealType>(mu_prior, sigma_prior), mu_prior);
    uniform_real_distribution<RealType> proposal {mu_prior - 5*sigma_prior, mu_prior + 5*sigma_prior};
    uniform_real_distribution<RealType> accept {0, maxval};
    RealType mu;

    cpprob::start_rejection_sampling();
    while (true) {
        mu = cpprob::sample(proposal, true);
        if (cpprob::sample(accept) <
            pdf(boost::math::normal_distribution<RealType>(mu_prior, sigma_prior), mu)) {
            break;
        }
    }
    cpprob::finish_rejection_sampling();

    normal_distribution<RealType> likelihood {mu, sigma};
    cpprob::observe(likelihood, y1);
    cpprob::observe(likelihood, y2);
    cpprob::predict(mu, "Mu");
}

template<std::size_t N>
void hmm(const std::array<double, N> & observed_states)
{
    using boost::random::normal_distribution;
    using boost::random::discrete_distribution;
    using boost::random::uniform_smallint;

    constexpr int k = 3;
    static const std::array<double, k> state_mean {{-1, 0, 1}};
    static const std::array<std::array<double, k>, k> T {{{{ 0.1,  0.5,  0.4 }},
                                                          {{ 0.2,  0.2,  0.6 }},
                                                          {{ 0.15, 0.15, 0.7 }}}};
    uniform_smallint<> prior {0, 2};
    auto state = cpprob::sample(prior, true);
    cpprob::predict(state, "State");
    for (const auto obs : observed_states) {
        discrete_distribution<> transition_distr {T[state].begin(), T[state].end()};
        state = cpprob::sample(transition_distr, true);
        cpprob::predict(state, "State");
        normal_distribution<> likelihood {state_mean[state], 1};
        cpprob::observe(likelihood, obs);
    }
}

void all_distr(int, int);
} // end namespace models
#endif  // INCLUDE_MODELS_HPP_
