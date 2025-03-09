CREATE TABLE issues (
    id SERIAL PRIMARY KEY,
    brand VARCHAR(50) NOT NULL,
    issue_type VARCHAR(50) NOT NULL,
    description TEXT NOT NULL,
    source_filter VARCHAR(20),
    output_filter VARCHAR(10),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
