LINKED * COMBINE(LINKED *START, LINKED *LAST)
{
    LINKED *TEMP = NULL;
    LINKED *SPTR = START, *LPTR = LAST;

    do
    {
        INSERT_END(&TEMP, SPTR->DATA);
        SPTR = SPTR->next;
    } while (SPTR->next != START);
    INSERT_END(&TEMP, SPTR->DATA);
    SPTR = SPTR->next;
    do
    {
        INSERT_END(&TEMP, LPTR->DATA);
        LPTR = LPTR->next;
    } while (LPTR->next != LAST);
    INSERT_END(&TEMP, LPTR->DATA);
    LPTR = LPTR->next;
    return TEMP;
}

void ADD_TWO_LIST(LINKED **START, LINKED *LAST)
{
    LINKED *SFIRST, *SLAST, *LFIRT, *LLAST;
    SFIRST = (*START);
    SLAST = (*START)->prev;
    LFIRT = (LAST);
    LLAST = (LAST->prev);

    (*START)->prev->next = LAST;
    LAST->prev = (*START)->prev;
    LLAST->next = (*START);
    (*START)->prev = LLAST;
}