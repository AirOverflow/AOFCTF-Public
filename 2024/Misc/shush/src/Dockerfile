FROM theflash2k/pwn-chal:py38

ENV CHAL_NAME=shush
COPY ${CHAL_NAME} .
RUN chmod +rx ${CHAL_NAME}

# Prevent unintended solutions:
ENV ENV=/etc/profile.d/aliases.sh
RUN rm -f /usr/local/bin/pip /usr/local/bin/pip3 && \
    chown root:root /var/tmp /tmp /run/lock /dev/shm /dev/mqueue /home/ctf-player && \
    chmod 770 /var/tmp /tmp /run/lock /dev/shm /dev/mqueue /home/ctf-player && \
    echo "alias exec=asdasdasdasd" > /etc/profile.d/aliases.sh && \
    echo "alias nohup=asdasdasdasd" >>  /etc/profile.d/aliases.sh && \
    echo "alias alias=asdasdasdasd" >>  /etc/profile.d/aliases.sh && \
    echo "alias env=asdasdasdasd" >>  /etc/profile.d/aliases.sh && \
    chmod 444 /etc/profile.d/aliases.sh 
EXPOSE 8000

# For dynamic flagging:
COPY docker-entrypoint.sh /tmp
RUN chmod +x /tmp/docker-entrypoint.sh
ENTRYPOINT [ "/tmp/docker-entrypoint.sh" ]
