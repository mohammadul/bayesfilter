/*
 *    bayesfilter - a c++ class package for Bayes filter
 *    Copyright (C) 2023 Sk. Mohammadul Haque
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "../include/kalmanfilter.h"

KalmanFilter::KalmanFilter(System& _sys, Observatory& _obs)
: BayesFilter(_sys, _obs)
{
    Qcurr = Eigen::MatrixXd(sys.state_dim, sys.state_dim);
    Rcurr = Eigen::MatrixXd(obs.observe_dim, obs.observe_dim);
}

KalmanFilter::~KalmanFilter()
{
}


bool KalmanFilter::predict(const Eigen::MatrixXd& u)
{
    sys(xprev, u, xcurr);
    sys.covtransform(Pprev, Qcurr, Pcurr);
    std::swap(Pprev, Pcurr);
    return true;
}


bool KalmanFilter::update(Eigen::MatrixXd& y)
{
    obs(xcurr, ycurr);
    auto res = y-ycurr;
    obs.covtransform(Pcurr, Rcurr, Scurr);
    //auto kgain = Pcurr*Scurr.transpose()*Scurr.inverse();
    //xcurr = xcurr+kgain*res;
    //Pcurr = (Eigen::Identity())
    return true;
}

bool KalmanFilter::iterate(const Eigen::MatrixXd& u, Eigen::MatrixXd& y)
{
    predict(u);
    update(y);
    return false;
}


