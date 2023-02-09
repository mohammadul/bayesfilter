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

#include "../include/error.h"

#include <iostream>

void error(ErrorType etype, const char* str)
{
    switch(etype)
    {
    case ErrorType::INFO:
        std::cout<<"[INFO]: "<<str<<std::endl;
        break;
    case ErrorType::WARNING:
        std::cout<<"[WARNING]: "<<str<<std::endl;
        break;
    case ErrorType::ERROR:
        std::cout<<"[ERROR]: "<<str<<std::endl;
        // exit(-1);
        break;
    }
}
