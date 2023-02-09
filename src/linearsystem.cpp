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

#include "../include/linearsystem.h"
//#include <iostream>

LinearSystem::LinearSystem(int _state_dim, int _input_dim) : System(_state_dim, _input_dim)
{
    A = Eigen::MatrixXd(_state_dim, _state_dim);
    B = Eigen::MatrixXd(_state_dim, _input_dim);
}

LinearSystem::LinearSystem(const Eigen::MatrixXd& _A, const Eigen::MatrixXd& _B) : System(_A.cols(), _B.cols()), A(_A), B(_B)
{
}

LinearSystem::~LinearSystem()
{
}

bool LinearSystem::operator()(const Eigen::MatrixXd& x, const Eigen::MatrixXd& u, Eigen::MatrixXd& xkp1)
{
    xkp1 = A*x+B*u;
    return true;
}

bool LinearSystem::covtransform(const Eigen::MatrixXd& Pcurr, const Eigen::MatrixXd& Qcurr, Eigen::MatrixXd& Pnew)
{
    Pnew = A*Pcurr*A.transpose()+Qcurr;
    return true;
}
