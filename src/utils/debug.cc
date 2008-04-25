/*
 * PDFedit - free program for PDF document manipulation.
 * Copyright (C) 2006, 2007, 2008  PDFedit team: Michal Hocko,
 *                                              Miroslav Jahoda,
 *                                              Jozef Misutka,
 *                                              Martin Petricek
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program (in doc/LICENSE.GPL); if not, write to the 
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, 
 * MA  02111-1307  USA
 *
 * Project is hosted on http://sourceforge.net/projects/pdfedit
 */
// vim:tabstop=4:shiftwidth=4:noexpandtab:textwidth=80
#include "kernel/static.h" // WIN32 port - precompiled headers - REMOVE IN FUTURE!
#include "debug.h"

// if default debug level doesn't come from gcc command line, we use
// ERR
#ifndef DEFAULT_DEBUG_LEVEL
#define DEFAULT_DEBUG_LEVEL debug::DBG_ERR
#endif

/** Prefix for debug messages. */
#define DEBUG_PREFIX "DEBUG"

namespace debug
{

unsigned int debugLevel = DEFAULT_DEBUG_LEVEL;

unsigned int changeDebugLevel(unsigned int level)
{
	// gets an old value and sets new
	unsigned int oldLevel=debugLevel;
	
	// logs change of level with DEBUG prefix to default output stream
	// temporarily sets debugLevel so that message is guaranteed to 
	// be printed
	debugLevel=DBG_INFO;
	printDbg(DEBUG_PREFIX, DBG_INFO, "debugLevel has changed from "<<oldLevel<<" to "<<level);
	
	debugLevel=level;
	return oldLevel;
}

// API logger initialization
ApiLogger::Logger ApiLogger::logger (std::cout, "API");

}
