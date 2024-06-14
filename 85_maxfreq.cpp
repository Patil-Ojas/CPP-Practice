
int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> mp;

    int freq = -1;

    for (int i=0; i<arr.size(); i++)
    {
        mp[arr[i]]++;
        
        if (mp[arr[i]] > freq)
        {
            freq = mp[arr[i]];
        }    
    }

    for (int i=0; i<arr.size(); i++)
        if (mp[arr[i]] == freq)
            return arr[i];
    
    return -1;
}
