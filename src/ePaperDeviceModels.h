//     ePaper Driver Lib for Arduino Project
//     Copyright (C) 2019 Michael Kamprath
//
//     This file is part of ePaper Driver Lib for Arduino Project.
// 
//     ePaper Driver Lib for Arduino Project is free software: you can 
//	   redistribute it and/or modify it under the terms of the GNU General Public License
//     as published by the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
// 
//     ePaper Driver Lib for Arduino Project is distributed in the hope that 
// 	   it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
// 
//     You should have received a copy of the GNU General Public License
//     along with Shift Register LED Matrix Project.  If not, see <http://www.gnu.org/licenses/>.
//
//     This project and its creators are not associated with Crystalfontz, Good display
//	   or any other manufacturer, nor is this  project officially endorsed or reviewed for 
//	   correctness by any ePaper manufacturer. 
//

#ifndef __ePaperDeviceModels__
#define __ePaperDeviceModels__

typedef enum {
	// Model: Crystalfontz CFAP104212*0-0213 - 2.13 Inch 3-color ePaper display
	CFAP104212C0_0213,		// red
	CFAP104212E0_0213,		// yellow 
	
	
	// model: Crystalfontz CFAP176264A0-0270 - 2.7 inch 3-color ePaper display
	CFAP176264A0_0270,
	
	// MODEL: Crystalfontz CFAP400300*0-0420 - 4.2 INCH 3-Color ePaper Display
	CFAP400300A0_420,		// red
	CFAP400300C0_420,		// yellow
	

} ePaperDeviceModel;

#endif //__ePaperDeviceModels__
