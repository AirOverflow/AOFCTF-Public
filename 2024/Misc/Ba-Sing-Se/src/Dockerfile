FROM theflash2k/pwn-chal:py38

ENV CHAL_NAME=ba-sing-se.py
COPY . .
RUN chmod +rx ${CHAL_NAME}

# For dynamic flagging:
RUN mv docker-entrypoint.sh /tmp/docker-entrypoint.sh
RUN chmod +x /tmp/docker-entrypoint.sh
ENTRYPOINT [ "/tmp/docker-entrypoint.sh" ]
