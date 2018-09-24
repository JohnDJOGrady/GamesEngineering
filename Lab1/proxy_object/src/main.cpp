/// <summary>
/// @mainpage Proxy Object Design Pattern lab - implementation
/// @author(s) John O'Grady
/// @version 1.0
/// @date 17/09/18 -> 23/09/18
/// @brief 
/// </summary>

#include <iostream>
#include "Proxy.h"

int main() 
{
	GraphicProxy proxy;
	proxy.Draw();
	std::cin.get();
}