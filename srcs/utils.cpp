//
// Created by Shandy Mephesto on 1/13/22.
//

#include "utils.hpp"

/**
 * split string with delimiter. It skips empty strings
 * @param s source string
 * @param delim delimiter string
 * @return vector of strings
 */

vector<string> ft_split(string s, const string& delimiter)
{
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	string token;
	vector<string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		if (!token.empty())
			res.push_back(token);
	}
	token = s.substr(pos_start);
	if (!token.empty())
		res.push_back(token);
	return res;
}

/**
 * Create pollFdPointer with pollFd structure
 * @param fd
 * @return
 */
pollfd* getPollFdFromFd(int fd)
{
	pollfd* pollfdPtr = new pollfd[1];
	pollfdPtr[0].fd = fd;
	pollfdPtr[0].events = POLLIN | POLLOUT;
	pollfdPtr[0].revents = 0;
	return pollfdPtr;
}

std::string ltrim(std::string str, const std::string& chars)
{
	str.erase(0, str.find_first_not_of(chars));
	return str;
}

std::string rtrim(std::string str, const std::string& chars)
{
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

std::string trim(std::string str, const std::string& chars) { return ltrim(rtrim(str, chars), chars); }

void sendMessage(int fd, string msg)
{
	cout << "sending message to " << fd << ": " << msg << endl;
	send(fd, msg.c_str(), msg.size(), 0);
}

int isChannelName(string channelName)
{
	if (channelName.empty() || (channelName[0] != '#' && channelName[0] != '&'))
		return 0;
	return 1;
}
