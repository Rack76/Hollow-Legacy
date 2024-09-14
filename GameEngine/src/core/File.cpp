#include "GameEngine/Core/File.h"
#include <sstream>
#include "GameEngine/Util/Util.h"
#include <windows.h>
#include <iostream>

namespace HollowEngine
{
	void File::setWorkingDirectory(const char* path)
	{
		assertNoAbort(SetCurrentDirectory(path) != 0, "could not open file ");
	}

	NameAllocator File::fileHandleAllocator;
	std::unordered_map<int, std::fstream> File::files;
}