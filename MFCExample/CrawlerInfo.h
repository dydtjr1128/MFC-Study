#ifndef CRAWLER_CRAWLER_INFO_H
#define CRAWLER_CRAWLER_INFO_H

#include <string>
#include <unordered_map>

namespace Crawler {
	class CrawlerInfo {
	private:
		std::string siteURL_;
		std::unordered_map<std::string,std::string> crawllingTagMap_;
	protected:
	public:
		explicit CrawlerInfo();
		virtual ~CrawlerInfo();

		std::string GetSiteURL() const;
		std::string GetCrallingTagByKey(const std::string& key) const;

		std::string PushCrallingTag(const std::string& key, const std::string& value);
		bool isKeyExist(std::string key);		
	};
}

#endif // !CRAWLER_CRAWLER_INFO_H