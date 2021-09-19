//---------------------------------------------------------------------------

#pragma hdrstop

#include "BookmarksWriter.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

void BookmarksWriter::writeBookmarks(std::vector<std::pair<std::string, std::string>> bookmarks, std::string path)
{
	std::ofstream writer;
    std::string line;
	writer.open(path);
	if (writer.is_open())
    {
		for (int i = 0; i < bookmarks.size(); ++i)
		{
			if(i + 1 == bookmarks.size())
			{
				writer << bookmarks[i].first + "=" + bookmarks[i].second;
			}
			else
			{
                writer << bookmarks[i].first + "=" + bookmarks[i].second << std::endl;
			}
		}
		writer.close();
	}
}
