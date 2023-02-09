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

#include "../include/linearobservatory.h"

LinearObservatory::LinearObservatory(int _state_dim, int _observe_dim)
:Observatory(_state_dim, _observe_dim)
{
    C = Eigen::MatrixXd(_observe_dim, _state_dim);
}

LinearObservatory::LinearObservatory(const Eigen::MatrixXd& _C) :Observatory(_C.cols(), _C.rows()), C(_C)
{
}

LinearObservatory::~LinearObservatory()
{
}

bool LinearObservatory::operator()(const Eigen::MatrixXd& x, Eigen::MatrixXd& ykp1)
{
    ykp1 = C*x;
    return true;
}

bool LinearObservatory::covtransform(const Eigen::MatrixXd& Pcurr, const Eigen::MatrixXd& Rcurr, Eigen::MatrixXd& Pnew)
{
    Pnew = C*Pcurr*C.transpose()+Rcurr;
    return true;
}

