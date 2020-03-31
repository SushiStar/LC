/*
 * TinyURL is a URL shortening service where you enter a URL such as
 * https://leetcode.com/problems/design-tinyurl and it returns a short URL such as
 * http://tinyurl.com/4e9iAk.
 *
 * Design the encode and decode methods for the TinyURL service. There is no
 * restriction on how your encode/decode algorithm should work. You just need to
 * ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded
 *
 * Date: 03/31/2020
 * Author: Wei Du
*/

class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (encode2decode.find(longUrl) == encode2decode.end()) {
            std::srand(std::time(nullptr));
            int l = longUrl.size()/2;
            std::string dec("");
            for(int i = longUrl.size()-1; i >= l; --i) {
                dec.append(1,longUrl[i]+ std::rand()%26);
            }
            encode2decode[longUrl] = new encdec(longUrl,dec);
            decode2encode[dec] = encode2decode[longUrl];
        }
        return encode2decode[longUrl]->second;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decode2encode[shortUrl]->first;
    }
private:
    typedef std::pair<std::string, std::string> encdec;
    std::unordered_map<std::string, encdec*> encode2decode;
    std::unordered_map<std::string, encdec*> decode2encode;
};
