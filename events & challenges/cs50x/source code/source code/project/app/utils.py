from transformers import pipeline
import praw
from googleapiclient.discovery import build

# Hugging Face summarizer
def summarize_text(text):
    summarizer = pipeline("summarization")
    summary = summarizer(text, max_length=50, min_length=25, do_sample=False)
    return summary[0]['summary_text']

# YouTube views fetcher 
def fetch_youtube_views(query):
    # Mock data
    return {"Video Title 1": 5000, "Video Title 2": 12000}

# Configure Reddit API
reddit = praw.Reddit(
    client_id='YOUR_CLIENT_ID',
    client_secret='YOUR_CLIENT_SECRET',
    user_agent='YOUR_USER_AGENT'
)

def fetch_reddit_posts(query):
    posts = []
    for submission in reddit.subreddit('all').search(query, limit=5):
        posts.append({
            "title": submission.title,
            "url": submission.url,
            "score": submission.score
        })
    return posts

# Configure Google Custom Search API
api_key = 'YOUR_GOOGLE_API_KEY'
cx = 'YOUR_CUSTOM_SEARCH_ENGINE_ID'

def fetch_google_search_results(query):
    service = build("customsearch", "v1", developerKey=api_key)
    res = service.cse().list(q=query, cx=cx, num=5).execute()
    results = []
    for item in res.get('items', []):
        results.append({
            "title": item['title'],
            "link": item['link'],
            "snippet": item['snippet']
        })
    return results
