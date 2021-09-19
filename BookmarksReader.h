//---------------------------------------------------------------------------

#ifndef BookmarksReaderH
#define BookmarksReaderH

#include <vector>
#include <utility>
#include <fstream>
#include <regex>

class BookmarksReader
{
	private:
	public:
		std::vector<std::pair<std::string, std::string>> readBookmarks(std::string path);


};
//---------------------------------------------------------------------------
#endif
