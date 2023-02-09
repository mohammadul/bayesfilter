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

#ifndef LINEARSYSTEM_H
#define LINEARSYSTEM_H

#include "system.h"

class LinearSystem : public System
{
    public:
    LinearSystem(int _state_dim, int _input_dim);
    LinearSystem(const Eigen::MatrixXd& _A, const Eigen::MatrixXd& _B);
    virtual ~LinearSystem();

    virtual bool operator()(const Eigen::MatrixXd& x, const Eigen::MatrixXd& u, Eigen::MatrixXd& xkp1);
    virtual bool covtransform(const Eigen::MatrixXd& Pcurr, const Eigen::MatrixXd& Qcurr, Eigen::MatrixXd& Pnew);

    //protected:
    Eigen::MatrixXd A;
    Eigen::MatrixXd B;
};


#endif // LINEARSYSTEM_H
