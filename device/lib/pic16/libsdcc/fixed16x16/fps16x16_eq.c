/*-------------------------------------------------------------------------
   fps16x16_eq.c - compare two __fixed16x16 values for equality

   Copyright (C) 2005, Raphael Neider <rneider at web.de> 

   This library is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2.1, or (at your option) any
   later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License 
   along with this library; see the file COPYING. If not, write to the
   Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA.

   As a special exception, if you link this library with other files,
   some of which are compiled with SDCC, to produce an executable,
   this library does not by itself cause the resulting executable to
   be covered by the GNU General Public License. This exception does
   not however invalidate any other reasons why the executable file
   might be covered by the GNU General Public License.
-------------------------------------------------------------------------*/

union u_t {
  long value;
  __fixed16x16 fix;
};

char
__fps16x16_eq (__fixed16x16 a, __fixed16x16 b)
{
  union u_t u1, u2;

  u1.fix = a;
  u2.fix = b;
  
  return (u1.value == u2.value);
}
