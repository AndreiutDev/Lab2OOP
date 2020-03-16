#pragma once

class rational
{
public:
	typedef struct r
	{
		int x;
		int y;
	}rationalNum;
	rational();
	void  rationalAdd(rationalNum x);
	void  rationalMul(rationalNum x);
	void  rationalQuot(rationalNum x);
	private:
		rationalNum result;
	
};

