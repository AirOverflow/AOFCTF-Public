FROM python:3.9

WORKDIR /code/app
COPY ./app /code/app
COPY docker-entrypoint.sh /docker-entrypoint.sh
RUN pip install -r /code/app/requirements.txt
EXPOSE 8899
ENTRYPOINT [ "/docker-entrypoint.sh" ]
