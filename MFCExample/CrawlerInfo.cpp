#include "pch.h"

#include "CrawlerInfo.h"

namespace Crawler {
	CrawlerInfo::CrawlerInfo()
	{
	}
	CrawlerInfo::~CrawlerInfo()
	{
	}
	std::string CrawlerInfo::GetSiteURL() const
	{
		return siteURL_;
	}

	std::string CrawlerInfo::GetCrallingTagByKey(const std::string& key) const
	{
		auto value = crawllingTagMap_.find(key);
		return value == crawllingTagMap_.end() ? value->second : nullptr;
	}

	std::string CrawlerInfo::PushCrallingTag(const std::string& key, const std::string& value)
	{
		return std::string();
	}

	bool CrawlerInfo::isKeyExist(std::string key)
	{
		return crawllingTagMap_.find(key) != crawllingTagMap_.end();
	}
} // namespace Crawler
