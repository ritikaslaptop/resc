# FixItYourself

#### Description: 'Do you really need to visit a service centre for that?'
This simple web-application asks for user's electronics' brand and issue type and helps them fix it through either listing out the solution stepwise using hugging face's ai summariser or simply redirects them to a helpful youtube video, using reddit and google as the relevant video/text sources

since i was asked for more details : this project, called 'fixityourself,' is a web app designed to help users troubleshoot issues with their devices. the project structure includes directories for the app's static files, templates, and necessary python modules. the backend uses flask and sql alchemy for the web framework and database interaction, while the frontend consists of html and css files for the user interface.

more detailed desc. : (had to use ai for this one 💀)

this project, called 'fixityourself,' is a comprehensive web application designed to assist users in troubleshooting issues with their devices. the project is structured to include directories for static files, templates, and essential python modules, leveraging a combination of flask, sqlalchemy, transformers, and other modern web development technologies to deliver an efficient and user-friendly experience.

project structure
the project directory is organized as follows:

app/: contains the main application code.

static/: holds static files such as css and javascript.
css/: directory for stylesheet files.
styles.css: main stylesheet for the application.
js/: directory for javascript files.
script.js: main javascript file for the application.
templates/: holds html template files.
index.html: the main landing page template.
results.html: the results page template.
init.py: initializes the flask application.
models.py: defines the database models using sqlalchemy.
routes.py: contains the route definitions and request handling.
utils.py: includes utility functions for text summarization and fetching youtube views.
migrations/: directory for database migration files.

database/: contains the database schema.

schema.sql: sql file for creating the database schema.
requirements.txt: lists the python packages required for the project.

run.py: the main entry point to run the flask application.

technologies and libraries used
backend
flask: a lightweight wsgi web application framework used for building the web application.
flask_sqlalchemy: an extension for flask that adds support for sqlalchemy, an orm (object-relational mapper) for database operations.
flask_migrate: an extension that handles sqlalchemy database migrations for flask applications using alembic.
transformers: a library from hugging face that provides state-of-the-art natural language processing models, used here for text summarization.
database
sqlite: a lightweight, disk-based database used for storing issues reported by users.
frontend
html: used for structuring the web pages.
css: used for styling the web pages. the stylesheet specifies a minimal design with rounded corners, the font as poppins, and the colors #00a282 and #f2ff49.
javascript: used for adding interactivity to the web pages.
