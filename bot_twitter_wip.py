import tweepy

consumer_key = '9uOHhK3fYikHPmhOOD5X0kwjo'
consumer_secret = 'TjNGn9OnpswpLXteTyZwsAzJlfAGGSkPibYw9CscyGcxD07aYm'
access_token = '1014714259371016192-kfp9Bvr9qNVG1ZiWJty0eMfa02dbCO'
access_token_secret = 'hY8h7WWdcr0sJiurFs95kankUlVucJN5hM6jE2MDz4VIj'

auth = tweepy.OAuth1UserHandler(consumer_key, consumer_secret, access_token, access_token_secret)
api = tweepy.API(auth)

# Misal, posting tweet
api.update_status("Hello, Twitter!")