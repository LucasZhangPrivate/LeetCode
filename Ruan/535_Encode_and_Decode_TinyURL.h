/*TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

Accepted*/

/*Runtime: 12 ms, faster than 30.30% of C++ online submissions for Encode and Decode TinyURL.
Memory Usage: 10.2 MB, less than 5.88% of C++ online submissions for Encode and Decode TinyURL.*/

//一道没啥意思的题
class Solution {
public:
    unordered_map<string, string> in;
    unordered_map<string, string> out;
    int n = 1;
    string shortbase = "http://tinyurl.com/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        auto index = in.find(longUrl);
        if (index != in.end())
        {
            auto s = index->second;
            return out.at(s);
        }
        else
        {
            string key = shortbase + to_string(n);
            n++;
            in.insert({ longUrl, key });
            out.insert({ key,longUrl });
            return key;
        }
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return out.at(shortUrl);
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));