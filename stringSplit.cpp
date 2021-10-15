// pass string and delimiter
vector<string> split(string &str, string delim = " ")
{
    vector<string> ans;
    string cur;
    long long int l = 0, r = 0, delSize = delim.size();

    while ((r = str.find(delim, l)) != string::npos)
    {
        cur = str.substr(l, r - l);
        l = r + delSize;
        ans.push_back(cur);
    }

    ans.push_back(str.substr(l));
    return ans;
}