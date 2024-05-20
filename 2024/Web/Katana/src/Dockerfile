FROM node:21-alpine

ENV LANG="C.UTF-8" PUPPETEER_SKIP_CHROMIUM_DOWNLOAD=true

RUN apk update
RUN apk add --no-cache zlib-dev udev nss ca-certificates
RUN apk add --no-cache chromium
RUN adduser -h /home/bot -D -u 10086 bot
RUN yarn cache clean
RUN rm -rf /tmp/* /etc/apk/* /var/cache/apk/* /usr/share/man

WORKDIR /home/bot

COPY . .
RUN npm install

#ENV APPURLREGEX="^http://127.0.0.1:3000/.*$"
ENV APPURLREGEX="^http://challs.airoverflow.com.*$"

RUN mv ./docker-entrypoint.sh /docker-entrypoint.sh

EXPOSE 3000

ENTRYPOINT [ "/docker-entrypoint.sh" ]
