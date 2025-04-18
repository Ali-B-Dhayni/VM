/*
*			Copyright (C) Ali B. Dhayni 2025
*	This software is free to use and distribute, falls under the terms of the
*	GNU General Public License as published by the Free Software Foundation,
*	either version 3 of the License, or any later version. 
*	The header of this file may not be changed in case of any other modification
*	or usage in other code bases.
*
*/


/*
*	 vm.hpp, Virtual Machine Header File
*	 System header file, declares the structure of the virtual machine.
*	 implementation is done vm.cpp
*/

#pragma once

#include <iostream>
#include "dhyutils.h"
#include "error.hpp"

void testfunction(void);

class
System
{
private:
	Terminal terminal;					
	Arena arena;
	P_Table p_table;
	Handler handler;
	Scheduler scheduler;

public:
	System(void){}

private:
	//system resources.
	Error sys_allocate_resources(void);
	Error sys_allocate_memory(void);
	//event handlers
	Error sys_handle_interaction(void);
};
