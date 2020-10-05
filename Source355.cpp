#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;


class Twitter {
	public:
		int c;
		unordered_map<int, unordered_set<int>> fans;
		unordered_map<int, vector<pair<int, int>>> posts;


		/** Initialize your data structure here. */
		Twitter() 
		{
			c = 0;
		}


		/** Compose a new tweet. */
		void postTweet(int userId, int tweetId) {

			follow(userId, userId);
			posts[userId].push_back({ c += 1, tweetId });

		}

		/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
		vector<int> getNewsFeed(int userId) {

			vector<int> ans;
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> p_que;

			
			for (auto &f : fans[userId])
			{
				for (auto &p : posts[f])
				{
					if (!p_que.empty() && p_que.size() > 10 && p_que.top().first > p.first)
					{
						break;
					}

					p_que.push(p);

					if (p_que.size() > 10)
					{
						p_que.pop();

					}

				}

			}

			while (!p_que.empty())
				{
					ans.push_back(p_que.top().second);
					p_que.pop();
				}

			reverse(ans.begin(), ans.end());

			return ans;

		}

		/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
		void follow(int followerId, int followeeId) {
			fans[followerId].insert(followeeId);

		}

		/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
		void unfollow(int followerId, int followeeId) {
			if (followerId != followeeId)
				{
					fans[followerId].erase(followeeId);
				}
			}
};


/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */


int main()
{
	Twitter* x = new Twitter();
	x->postTweet(1, 5);
	vector<int> x1 = x->getNewsFeed(1);

	for (int i : x1)
	{
		cout << i;
	}
	cin.get();

	x-> follow(1,2);
	x-> postTweet(2, 6);
	vector<int> x2 = x->getNewsFeed(1);

	for (int i : x2)
	{
		cout << i;
	}
	cin.get();

	x-> unfollow(1,2);
	vector<int> x3 = x->getNewsFeed(1);


	for (int i : x3)
	{
		cout << i;
	}
	cin.get();

}

