int charToInt(const char& c)
{
	int ret = -4;
	if (c == '+')
		ret = -3;
	else if (c == '-')
		ret = -2;
	else if (c == '.')
		ret = -1;
	else if ('0' <= c && c <= '9')
		ret = c - '0';
	return ret;
}

float stringToFloat(const string &s)
{
	string beforeDot, afterDot;
	int pos = s.find('.');
	beforeDot = s;
	if (pos != string::npos)
	{
		beforeDot = s.substr(0, pos );
		if (pos != s.size() - 1)
			afterDot = s.substr(pos + 1);
	}
	float bDot = 0, aDot = 0;
	int sign = 1;
	for (int i = 0; i < beforeDot.size(); i++)
	{
		int tmp = charToInt(beforeDot[i]);
		if (tmp == -4)
			return 0;
		if (tmp <= -2)
		{
			if (i != 0)
				return 0;
			if (tmp == -2)
				sign = -1;
			continue;
		}
		bDot = bDot * 10 + tmp;
	}
	bDot *= sign;
	for (int j = 0; j < afterDot.size(); j++)
	{
		int tmp = charToInt(afterDot[j]);
		if (tmp < -1)
			return 0;
		aDot = aDot * 10 + tmp;
	}
	while (aDot > 1)
	{
		aDot = aDot / 10.0;
	}
	aDot *= sign;
	return aDot + bDot;
}
