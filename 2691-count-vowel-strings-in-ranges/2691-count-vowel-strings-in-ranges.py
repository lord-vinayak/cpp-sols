class Solution(object):
    def vowelStrings(self, words, queries):
        """
        :type words: List[str]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        prefix = [0]
        cnt = 0
        for word in words:
            if word[0] in 'aeiou' and word[-1] in 'aeiou':
                cnt += 1
            prefix.append(cnt)
        res = []
        for l, r in queries:
            res.append(prefix[r + 1] - prefix[l])
        return res
        