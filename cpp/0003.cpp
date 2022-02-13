class Solution {
public:
  int lengthOfLongestSubstring(string s)
  {
    int size = s.size();
    int idx_substring = 0;
    int max_substring_length = 0;
    int current_substring_length = 0;
    unordered_map<char, int> map;
    for (int i = 0; i < size; ++i)
    {
      const char& c = s[i];
      const auto& map_it = map.find(c);
      // Haven't seen this character before
      if (map_it == map.end())
      {
        ++current_substring_length;
        map[c] = i;
        continue;
      }
      // If we have seen it before and it was last seen after
      // the start of the substring
      else if (map_it->second >= idx_substring)
      {
        if (current_substring_length > max_substring_length)
        {
          max_substring_length = current_substring_length;
        }
        idx_substring = map_it->second + 1;
        current_substring_length = i - map_it->second;
      }
      else
      {
        ++current_substring_length;
      }
      map[c] = i;
    }
    if (current_substring_length > max_substring_length)
    {
      max_substring_length = current_substring_length;
    }
    return max_substring_length;
  }
};

// Feb 2022
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int i = 0;
        std::unordered_set<char> char_in_window;
        for (int j = 0; j < s.size(); ++j) {
            while (char_in_window.find(s[j]) != char_in_window.end()) {
                auto it = char_in_window.find(s[i]);
                char_in_window.erase(it);
                ++i;
            }
            char_in_window.emplace(s[j]);
            max_length = std::max(max_length, static_cast<int>(char_in_window.size()));
        }
        return max_length;
    }
};
