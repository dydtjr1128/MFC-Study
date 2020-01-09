#ifndef CRAWLER_CRAWLER_H
#define CRAWLER_CRAWLER_H

#include <string>

namespace Crawler {
	class Crawler {
	private:
		std::string siteURL_ = nullptr;
	protected:
	public:			
		Crawler();
		virtual ~Crawler();

		virtual void StartCrawlling() = 0;
		virtual void StopCrawlling() = 0;

		std::string getSiteURL() {
			return siteURL_;
		}
	};

}

#endif // !CRAWLER_CRAWLER_H