from flask import render_template, request, redirect, url_for
from app import app, db
from app.models import Issue
from app.utils import summarize_text, fetch_youtube_views, fetch_reddit_posts, fetch_google_search_results

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/search', methods=['POST'])
def search():
    # Capture form data
    brand = request.form['brand']
    issue_type = request.form['issue_type']
    description = request.form['description']
    source_filter = request.form['source_filter']
    output_filter = request.form['output_filter']

    # Save to DB
    issue = Issue(brand=brand, issue_type=issue_type, description=description,
                  source_filter=source_filter, output_filter=output_filter)
    db.session.add(issue)
    db.session.commit()

    # Fetch and summarize results
    summarized_text = summarize_text(description)
    video_views = fetch_youtube_views(description)

    if source_filter == 'reddit':
        external_results = fetch_reddit_posts(description)
    elif source_filter == 'google':
        external_results = fetch_google_search_results(description)
    else:
        external_results = []

    return render_template('results.html', 
                           summarized_text=summarized_text, 
                           video_views=video_views,
                           external_results=external_results)
