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

#ifndef BAYESFILTER_H
#define BAYESFILTER_H

#include "common.h"
#include "system.h"
#include "observatory.h"


class BayesFilter
{
    public:
        BayesFilter(System& _sys, Observatory& _obs); //int _state_dim, int _input_dim, int _observe_dim
        virtual ~BayesFilter();
        virtual bool predict(const Eigen::MatrixXd& u);
        virtual bool update();
        virtual bool update(Eigen::MatrixXd& y);
        virtual bool iterate(const Eigen::MatrixXd& u, Eigen::MatrixXd& y);

    protected:
        Eigen::MatrixXd xcurr, xprev; // state vectors
        Eigen::MatrixXd ycurr; // observation vectors

        Eigen::MatrixXd Pprev, Pcurr, Scurr; // state covariance and measurement covariance

        System& sys;
        Observatory& obs;

};

#endif // BAYESFILTER_H
