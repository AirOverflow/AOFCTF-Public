FROM python:3.11

RUN apt-get update && apt-get install -y libzbar0

WORKDIR /code/app

COPY ./app /code/app
RUN mkdir /code/app/static/qr_code

COPY flag.txt /flag.txt

RUN pip install -r /code/app/requirements.txt
COPY docker-entrypoint.sh /docker-entrypoint.sh

EXPOSE 8899

ENTRYPOINT [ "/docker-entrypoint.sh" ]
