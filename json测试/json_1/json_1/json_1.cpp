// json_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "json/json.h"
#include <string>
using namespace std;

//{
//	"name": "json″,
//	"array": 
//	[
//		{
//			"cpp": "jsoncpp"
//		},
//		{
//			"java": "jsoninjava"
//		},
//		{
//			"php": "support"
//		}
//	]
//}

void readJson() 
{
	using namespace std;
	std::string strValue = "{\"name\":\"json\",\"array\":[{\"cpp\":\"jsoncpp\"},{\"java\":\"jsoninjava\"},{\"php\":\"support\"}]}";

	Json::Reader reader;
	Json::Value value;

	if (reader.parse(strValue, value))
	{   
		std::string out = value["name"].asString();
		std::cout << out << std::endl;
		const Json::Value arrayObj = value["array"];
		for (unsigned int i = 0; i < arrayObj.size(); i++)
		{   
			if (!arrayObj[i].isMember("cpp")) 
				continue;
			out = arrayObj[i]["cpp"].asString();
			std::cout << out;
			if (i != (arrayObj.size() - 1)) 
				std::cout << std::endl;
		}   
	}   
}


void writeJson() {
	using namespace std;

	Json::Value root;
	Json::Value arrayObj;
	Json::Value item;

	item["cpp"] = "jsoncpp";
	item["java"] = "jsoninjava";
	item["php"] = "support";
	arrayObj.append(item);

	root["name"] = "json";
	root["array"] = arrayObj;

	root.toStyledString();
	std::string out = root.toStyledString();
	std::cout << out << std::endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	readJson();
	writeJson();
	return 0;
}

