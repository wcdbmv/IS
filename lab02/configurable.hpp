#pragma once

class Configurable {
public:
	virtual void connect(int from, int to) = 0;
	virtual ~Configurable() = default;
};
