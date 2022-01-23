# pragma once
// Copyright 2021
//     Use, modification and distribution is subject to the Boost Software
//     License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//     http://www.boost.org/LICENSE_1_0.txt)
//  Authors: bujimi
#include <string>
#include <memory>
#include <functional>
/************************************************************************/
/*      
                                                                        */
/************************************************************************/
struct DirMonitor
{
	enum EventType
	{
		error = -1,
		null = 0,
		added = 1,
		removed = 2,
		modified = 3,
		renamed_old_name = 4,
		renamed_new_name = 5,
		recursive_rescan = 6
	};

	DirMonitor();
	~DirMonitor();

	void addDir(const std::string& dirname);
	void removeDir(const std::string& dirname);
	bool doMonitor();
	void handlerEvent(std::function<void(int ev, const std::string& path, const std::string& msg)> func);
private:
	struct Impl;
	std::shared_ptr<Impl> pImpl;
};
