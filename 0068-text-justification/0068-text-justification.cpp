class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        int n = words.size();
        int i = 0;
        int prev = 0;
        int wordsLength = 0;
        vector<string> ans;

        while (i < n) {

            int w = wordsLength + words[i].length() + (i - prev);

            // word cannot fit in current line
            if (w > maxWidth) {

                int noOfWords = i - prev;
                string s;

                // case 1: only one word in line
                if (noOfWords == 1) {
                    s += words[prev];

                    int spaces = maxWidth - words[prev].length();
                    while (spaces > 0) {
                        s += " ";
                        spaces--;
                    }
                }
                // case 2: multiple words
                else {
                    int gapBetWords = noOfWords - 1;
                    int noOfGaps = maxWidth - wordsLength;
                    int spaces = noOfGaps / gapBetWords;
                    int extraspaces = noOfGaps % gapBetWords;

                    int j = prev;
                    while (j < i) {
                        s += words[j];

                        if (j < i - 1) {
                            int k = spaces;
                            while (k > 0) {
                                s += " ";
                                k--;
                            }
                            if (extraspaces > 0) {
                                s += " ";
                                extraspaces--;
                            }
                        }
                        j++;
                    }
                }

                ans.push_back(s);
                prev = i;
                wordsLength = 0;
                continue;   // reprocess current word
            }

            // word fits in current line
            wordsLength += words[i].length();
            i++;
        }

        // last line (left justified)
        string lastLine;
        int j = prev;
        while (j < n) {
            lastLine += words[j];
            if (j < n - 1) {
                lastLine += " ";
            }
            j++;
        }

        int remaining = maxWidth - lastLine.length();
        while (remaining > 0) {
            lastLine += " ";
            remaining--;
        }

        ans.push_back(lastLine);
        return ans;
    }
};
