from app import db

class Issue(db.Model):
    __tablename__ = 'issues'
    id = db.Column(db.Integer, primary_key=True)
    brand = db.Column(db.String(50), nullable=False)
    issue_type = db.Column(db.String(50), nullable=False)
    description = db.Column(db.Text, nullable=False)
    source_filter = db.Column(db.String(20))
    output_filter = db.Column(db.String(10))
    created_at = db.Column(db.DateTime, default=db.func.now())
