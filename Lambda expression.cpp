#include <iostream>
#include <vector>
#include <algorithm> // sort, all_of, for_each
using namespace std;

bool cmp_desc(int a,int b) {
    return a>b; //降序
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> scores(n);
    cout << "Enter scores:\n";
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    // 1. 使用 Lambda 对分数进行降序排序
    sort(scores.begin(), scores.end(), [](int a, int b) { return a < b; }
         /* TODO: Lambda 表达式，按分数从高到低排序 */);

    // 2. 使用 Lambda 判断是否所有学生分数 >= 60
    bool allPassed = all_of(scores.begin(), scores.end(), [](int score) { return score >= 60; }
         /* TODO: Lambda 表达式，判断分数是否 >= 60 */);

    // 3. 如果不是所有人都及格，则使用 Lambda 给低于 60 分的加 5 分
    if (!allPassed) {
        for_each(scores.begin(), scores.end(),[](int& score){if (score < 60) {
            score += 5;
                 };}
                 /* TODO: Lambda 表达式，分数 < 60 时加 5 分 */);
    }

    // 输出排序后的成绩
    cout << "\nSorted scores:\n";
    for (int score : scores) {
        cout << score << " ";
    }
    cout << "\nAll students passed: " << (allPassed ? "Yes" : "No") << endl;

    return 0;
}
