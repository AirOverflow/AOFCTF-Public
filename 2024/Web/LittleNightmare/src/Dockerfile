FROM python:3.10

WORKDIR /app
COPY ./app /app
COPY flag.txt /flag

RUN pip3 install aiohttp==3.9.1

COPY docker-entrypoint.sh /docker-entrypoint.sh
EXPOSE 1337

ENTRYPOINT [ "/docker-entrypoint.sh" ]
