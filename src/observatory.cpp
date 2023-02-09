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

#include "../include/observatory.h"

Observatory::Observatory(int _state_dim, int _observe_dim)
    : state_dim(_state_dim), observe_dim(_observe_dim)
{
}

Observatory::~Observatory()
{
}

bool Observatory::operator()(const Eigen::MatrixXd& x, Eigen::MatrixXd& ykp1)
{
    error(ErrorType::ERROR, "should not have come to Observatory::operator()(const Eigen::MatrixXd& x, Eigen::MatrixXd& ykp1)");
    return false;
}

bool Observatory::covtransform(const Eigen::MatrixXd& Pcurr, const Eigen::MatrixXd& Rcurr, Eigen::MatrixXd& Pnew)
{
    error(ErrorType::ERROR, "should not have come to System::covtransform(const Eigen::MatrixXd& Pcurr, const Eigen::MatrixXd& Qcurr, Eigen::MatrixXd& Pnew)");
    return false;
}


