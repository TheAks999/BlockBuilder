#include "goc_cartloc.h"

float GOC_CartLoc :: x()
{
	return m_x;
}

float GOC_CartLoc :: y()
{
	return m_y;
}

float GOC_CartLoc :: z()
{
	return m_z;
}

void GOC_CartLoc :: x(const float & X)
{
	m_x = X;
}

void GOC_CartLoc :: y(const float & Y)
{
	m_y = Y;
}

void GOC_CartLoc :: z(const float & Z)
{
	m_z = Z;
}

