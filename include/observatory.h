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

#ifndef OBSERVATORY_H
#define OBSERVATORY_H

#include "common.h"

class Observatory
{
    public:
        Observatory(int _state_dim, int _observe_dim);
        virtual ~Observatory();
        virtual bool operator()(const Eigen::MatrixXd& x, Eigen::MatrixXd& ykp1);
        virtual bool covtransform(const Eigen::MatrixXd& Pcurr, const Eigen::MatrixXd& Rcurr, Eigen::MatrixXd& Pnew);

    //protected:
    int state_dim, observe_dim;
};

#endif // OBSERVATORY_H
