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

#include "../include/bayesfilter.h"

BayesFilter::BayesFilter(System& _sys, Observatory& _obs) : sys(_sys), obs(_obs)
{
    xprev = Eigen::MatrixXd(_sys.state_dim, 1);
    xcurr = Eigen::MatrixXd(_sys.state_dim, 1);
    ycurr = Eigen::MatrixXd(_obs.observe_dim, 1);
    Pcurr = Eigen::MatrixXd(_sys.state_dim, _sys.state_dim);
    Pprev = Eigen::MatrixXd(_sys.state_dim, _sys.state_dim);
    Scurr = Eigen::MatrixXd(_obs.observe_dim, _obs.observe_dim);
}

BayesFilter::~BayesFilter()
{
}

bool BayesFilter::predict(const Eigen::MatrixXd& u)
{
    error(ErrorType::ERROR, "should not have come to BayesFilter::predict(const Eigen::MatrixXd&)");
    return false;
}

bool BayesFilter::update()
{
    error(ErrorType::ERROR, "should not have come to BayesFilter::update()");
    return false;
}

bool BayesFilter::update(Eigen::MatrixXd& y)
{
    error(ErrorType::ERROR, "should not have come to BayesFilter::update(Eigen::MatrixXd&)");
    return false;
}

bool BayesFilter::iterate(const Eigen::MatrixXd& u, Eigen::MatrixXd& y)
{
    error(ErrorType::ERROR, "should not have come to BayesFilter::iterate(const Eigen::MatrixXd&, Eigen::MatrixXd&)");
    return false;
}
