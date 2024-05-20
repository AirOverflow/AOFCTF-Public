FROM theflash2k/pwn-chal:py38
RUN pip3 install pycryptodome

ENV CHAL_NAME="impurity.py"
COPY ${CHAL_NAME} /app/${CHAL_NAME} 
RUN chmod a+x ${CHAL_NAME}

# For setting up the dynamic flagging.
COPY docker-entrypoint.sh /tmp/docker-entrypoint.sh
RUN chmod +x /tmp/docker-entrypoint.sh
ENTRYPOINT [ "/tmp/docker-entrypoint.sh" ]
