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

#include <iostream>
#include "../include/kalmanfilter.h"
#include "../include/linearsystem.h"
#include "../include/linearobservatory.h"

using namespace std;

#define MAP_SIZE (256)

int main(int argc, char* argv[])
{
    const int state_dim = (2+MAP_SIZE), input_dim = 2, observe_dim = MAP_SIZE;
    LinearSystem ls(state_dim, input_dim);
    LinearObservatory lo(state_dim, observe_dim);
    KalmanFilter kf(ls, lo);
    Eigen::MatrixXd u(input_dim,1), y(observe_dim,1);
    kf.iterate(u,y);
    return 0;
}

