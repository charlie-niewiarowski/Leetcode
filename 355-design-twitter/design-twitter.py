class Twitter:
    def __init__(self):
        self.userToFollowees = collections.defaultdict(lambda: set())
        self.userTweets = collections.defaultdict(lambda: list()) 
        self.time = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.userTweets[userId].append((self.time, tweetId))
        self.time -= 1

    def getNewsFeed(self, userId: int) -> List[int]:
        res = []
        minHeap = []

        self.userToFollowees[userId].add(userId)
        for followeeId in self.userToFollowees[userId]:
            if followeeId in self.userTweets:
                index = len(self.userTweets[followeeId]) - 1
                count, tweetId = self.userTweets[followeeId][index]
                heapq.heappush(minHeap, [count, tweetId, followeeId, index - 1])

        while minHeap and len(res) < 10:
            count, tweetId, followeeId, index = heapq.heappop(minHeap)
            res.append(tweetId)
            if index >= 0:
                count, tweetId = self.userTweets[followeeId][index]
                heapq.heappush(minHeap, [count, tweetId, followeeId, index - 1])
        return res


    def follow(self, followerId: int, followeeId: int) -> None:
        self.userToFollowees[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.userToFollowees[followerId]:
            self.userToFollowees[followerId].remove(followeeId)
        


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)