﻿/*
* Author:
* File: main.cpp Date: 2/13/20
* Class: CS 5201
* Instructor :
*
* SIRD file
*/

#ifndef SIRD_H
#define SIRD_H


#include <iostream>
#include <functional>
#include "vector.h"
#include "Euler.h"

using std::cout;
using std::function;
using std::ostream;


class SIRD
{
private:

  double h;
  vector<double> vRates;
  vector<double> state;
  Euler<vector<double>> SIRDeuler;

  void createODE();
  //void init(double init_population, double init_infected, double step_size, vector<double>& v_input);
public:

  /*
  A constructor accepting the initial total population (N0), 
  the initial number of infected (I0), 
  and a step size (h), and a vector [β,ν,δ], 
  which should default to values provided in the driver instructions
  */

  /*!
  * @brief Default Constructor
  * @brief β=0.01, ν=0.1, and δ=0.05
  * @brief h=0.1 
  * @brief vector {S=99,I=1,R=0.0,D=0.0}
  * @post creates SIRD object with default values
  */
  SIRD();


  /*!
  * @brief creates SIRD object with given paramater
  * @param[in] init_population > init_infected
  * @param[in] init_infected < init_population
  * @param[in] step_size non zero positive number
  * @param[in] v_input rate to be used in ODE
  * @pre init_population,init_infected, step_size
  * @pre should all be positive integers
  * @pre init_population > init_infected
  * @pre all should be non zeros
  * @post creates SIRD object with specified values
  * @note v_input values should be reasonable but left up to user
  */
  SIRD(double init_population, double init_infected, double step_size, 
    vector<double> v_input);

  /*!
  * @brief steps default h
  * @post steps Euler object with default step (h)
  */

  void operator()();

  /*!
  * @brief steps given input_step
  * @param[in] input_non zero step positive number
  * @post steps Euler object with input_step given
  */
  void operator()(double input_step);

  /*!
  * @brief outputes state vector values of Obj
  * @param[in] os ostream object
  * @param[in] Obj SIRD object to print values from
  * @post prints values in form
 Susceptible: <S>, Infected: <I>, Recovered: <R>, Deceased: <D>
  */

  friend ostream& operator << (ostream& os, const SIRD& Obj);

  /*!
  * @brief copies source contents to this object
  * @param[in] source SIRD reference
  * @post copies contents of SIRD to this if not same
  */

  SIRD& operator = (const SIRD& source);
    
};

//#include "SIRD.cpp"

#endif
