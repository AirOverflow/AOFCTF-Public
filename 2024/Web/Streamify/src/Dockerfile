FROM node:14

RUN apt-get update && apt-get install -y netcat

WORKDIR /app

COPY ./app .

COPY ./flag.txt /flag.txt

RUN npm install

EXPOSE 8899

COPY docker-entrypoint.sh /docker-entrypoint.sh

ENTRYPOINT [ "/docker-entrypoint.sh" ]
